#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define S second
#define F first
#define f(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define precise(x) fixed << setprecision(x) 

int n,k,A;
int l[10];
int b[10];
int temp[10];

double go()
{
    double res = 0.00000000;
    
    
    for(int mask=0;mask<(1LL<<n);mask++)
    {
        int cnt = 0;
        int B = 0;
        double happen = 1.00000000000;
        
        f(j,n) if(mask&(1LL<<j))
        {
            happen*=((double)(100-l[j])/100.0000000);   
            cnt++;  B+=b[j];
        }
        else happen*=(double)l[j]/100.000000;
        
        double kill = (double)A/(double)(A+B);
 
        if(cnt < n-cnt) res+=(happen);
        else res+=(happen*kill);
    }
    
    return res;
}
  
double recur(int id,int left)
{
    if(id == n-1)
    {
        l[id] = min(100,l[id]+(left*10));
        double res = go();
        l[id] = temp[id];
        return res;
    }
    
    double best = 0.00000;
    
    for(int give=0;give<=left;give++)
    {
       if(temp[id] + (give*10) > 100) break;
       l[id] = temp[id] + (10*give);   
       best = max(best,recur(id+1,left-give));
    }
    
    l[id] = temp[id];
    
    return best;
}

void solve()
{
  cin >> n >> k >> A;
    
  f(i,n) cin >> b[i] >> l[i];
  f(i,n) temp[i] = l[i];
    
  cout << precise(10) << recur(0,k);  
}

signed main()
{
    fast;
    solve();
}