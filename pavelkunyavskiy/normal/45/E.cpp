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

vector<string> names[26];
vector<string> surnames[26];

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        names[s[0]-'A'].pb(s);
    }
    for (int i=0;i<n;i++){
        string s;
        cin>>s;
        surnames[s[0]-'A'].pb(s);
    }
    for (int i=0;i<26;i++){
        sort(names[i].begin(),names[i].end());
        sort(surnames[i].begin(),surnames[i].end());
        reverse(names[i].begin(),names[i].end());
        reverse(surnames[i].begin(),surnames[i].end());

    }
    
    string ans;
    for (int i=0;i<26;i++){
        for (;names[i].size()>0;){
            if (names[i].size()>surnames[i].size()){
                bool q=false;
                for (int j=0;j<i;j++)
                    if (surnames[j].size()>names[j].size()){
                        ans+=names[i].back()+" "+surnames[j].back()+", ";
                        surnames[j].pop_back();
                        names[i].pop_back();
                        q=true;
                        break;
                    }
                if (q)
                    continue;
            }
            if (surnames[i].size()!=0){
                ans+=names[i].back()+" "+surnames[i].back()+", ";
                surnames[i].pop_back();
                names[i].pop_back();
                continue;
            }
            for (int j=0;j<26;j++)
                if (surnames[j].size()>names[j].size()){
                    ans+=names[i].back()+" "+surnames[j].back()+", ";
                    surnames[j].pop_back();
                    names[i].pop_back();
                    break;
                }
        }
    }   
    ans.erase(--ans.end());
    ans.erase(--ans.end());
    cout<<ans<<endl;
    return 0;
}