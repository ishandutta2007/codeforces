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
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define setval(a,v) memset(a,v,sizeof(a))
#define forn(i,n) for(int i=0;i<(n);++i)
#define ford(i,n) for(int i=(n)-1;i>=0;--i)

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long long ll;
typedef long double ld;



int n;

void print(vector <vector <int> > a){
    forn(i, a.size())
        sort(a[i].begin(),a[i].end());
    sort(a.begin(), a.end());
    for (int i=0;i<a.size();i++){
        printf("{");
        for (int j=0;j<a[i].size();j++){
            printf("%d",a[i][j]);
            if (j+1!=a[i].size())
                printf(",");
        }
        printf("}");
        if (i!=a.size()-1)
            printf(",");
    }
    printf("\n");       
}

vector<vector<int> > ans[200000];
int sz;
vector<vector<int> > ans1[200000];
int sz1;

void iterate(int n){
    for (int i=0;i<sz1;i++){
        ans[i].swap(ans1[i]);
        ans1[i].clear();            
    }
    sz=sz1;
    sz1=0;
    for (int i=0;i<sz;i++){
        int tmp=ans[i].size();
        if (i==0 || ans1[sz1-1][0].back()==n){
            for (int j=0;j<tmp;j++){
                ans1[sz1+j]=ans[i];
                ans1[sz1+j][j].pb(n);
            }
            ans1[sz1+tmp]=ans[i];
            ans1[sz1+tmp].pb(vector<int>());
            ans1[sz1+tmp][tmp].pb(n);
            sz1+=tmp+1;
            continue;
        }
        for (int j=0;j<tmp;j++){
                ans1[sz1+j]=ans[i];
                ans1[sz1+j][j].pb(n);
            }
        ans1[sz1+tmp]=ans[i];
        ans1[sz1+tmp].pb(vector<int>());
        ans1[sz1+tmp][tmp].pb(n);
        reverse(ans1+sz1,ans1+sz1+tmp+1);
        sz1+=tmp+1;
    }   
}



int main()
{
  #ifndef ONLINE_JUDGE
    ld start=clock();
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin >> n;
    ans1[0].pb(vector<int>());
    ans1[0][0].pb(1);
    sz1=1;
    for (int i=2;i<=n;i++)
        iterate(i);
    cout<< sz1<<endl;
    for (int i=0;i<sz1;i++)
        print(ans1[i]);
          
  #ifndef ONLINE_JUDGE
    cerr<<(clock()-start)/CLOCKS_PER_SEC<<endl;
  #endif
    return 0;
}