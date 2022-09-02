#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <iterator>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))

#define dbg(v) copy(v.begin(),v.end(),ostream_iterator<int>(cerr," "))

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;


int l[10][10],r[10][10],a[10][10];
int n;

struct state{
    vector<int> rasb;
    int last;
};

bool operator<(const state& a,const state& b){
    if (a.rasb != b.rasb)
        return a.rasb < b.rasb;
    return a.last < b.last;
}

void norm(state& s){
    s.last = 0;
    s.rasb.pop_back();  
}


map<state,int> t;

const int inf=1<<25;

int calc(state s){
    if (s.rasb.back() < 0)
        return -inf;
    
//  dbg(s.rasb);
//  cerr<<s.last<<endl; 
    if (s.last == s.rasb.size()){
        if (s.rasb.back() != 0)
            return -inf;
        norm(s);
    }
    if (s.rasb.size() <= 1)
        return 0;
    if (t.find(s) != t.end())
        return t[s];
    int& ans=t[s];
    ans=-inf;
    int v=s.rasb.size()-1;
    int to=s.last;
    s.last++;
    for (int i=l[v][to];i<=r[v][to];i++){
        s.rasb[v]-=i;
        s.rasb[to]+=i;
        ans=max(ans,calc(s)+a[v][to]*(i>0)+i*i);
        s.rasb[v]+=i;
        s.rasb[to]-=i;
    }
    return ans;
}




int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    scanf("%d",&n);
    int m=n*(n-1)/2;
    for (int i=0;i<m;i++){
        int a,b,lf,rg,ac;
        cin>>a>>b>>lf>>rg>>ac;
        --a;--b;
        l[b][a]=lf;
        r[b][a]=rg;
        ::a[b][a]=ac;
    }
    
    state s;
    s.rasb.resize(n);
    s.last = 0;
    for (int i=0;i<=25;i++){
        s.rasb.back()=i;        
        int tmp=calc(s);
        t.clear();
        if (tmp >= 0){
            cout<< i<<" "<<tmp << endl;
            return 0;
        }
    }
    
    cout << -1 << " " <<-1 << endl;
    
    return 0;
}