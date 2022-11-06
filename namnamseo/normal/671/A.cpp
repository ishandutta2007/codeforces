#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args> void read(T& a,Args&... b){ read(a); read(b...); }

int n;

int p,q,r,s,t,u;

int dx[100010];
int dy[100010];

double cd(int a,int b,int c,int d){
    return sqrt((a-c)*1.0*(a-c) + (b-d)*1.0*(b-d));
}

double pA[100010];
double pB[100010];

int main()
{
    read(p,q,r,s,t,u);
    read(n);
    int i;
    for(i=1;i<=n;++i) read(dx[i], dy[i]);
    
    double ans=1e300;
    
    // case 1: A do it all
    {
        double firstMin = 1e300, sumA=0;
        for(i=1;i<=n;++i){
            double d0 = cd(p,q,dx[i],dy[i]);
            double d1 = cd(t,u,dx[i],dy[i]);
            sumA += 2*d1;
            firstMin = min(firstMin, d0-d1);
        }
        ans = min(ans, firstMin + sumA);
    }
    
    // case 2: B do it all
    {
        double firstMin = 1e300, sumA=0;
        for(i=1;i<=n;++i){
            double d0 = cd(r,s,dx[i],dy[i]);
            double d1 = cd(t,u,dx[i],dy[i]);
            sumA += 2*d1;
            firstMin = min(firstMin, d0-d1);
        }
        ans = min(ans, firstMin + sumA);
    }
    
    // both do at least one
    
    if(n>=2){
        typedef pair<double, int> pdi;
        
        set<pair<double, int> > sa, sb;
        
        double sum=0;
        
        for(i=1;i<=n;++i){
            double d0=cd(t,u,dx[i],dy[i]);
            sum += 2*d0;
            sa.insert(pdi(pA[i]=cd(p,q,dx[i],dy[i])-d0, i));
            sb.insert(pdi(pB[i]=cd(r,s,dx[i],dy[i])-d0, i));
        }
        
        pdi ta, tb;
        
        ta=*sa.begin();
        i=ta.second;
        tb=pdi(pB[i], i);
        sb.erase(tb);
        ans=min(ans, sum + ta.first + sb.begin() -> first);
        sb.insert(tb);
        
        tb=*sb.begin();
        i=tb.second;
        ta=pdi(pA[i], i);
        sa.erase(ta);
        ans=min(ans, sum + tb.first + sa.begin() -> first);
        sa.insert(ta);
    }
    
    printf("%.14f\n",ans);
    
    return 0;
}