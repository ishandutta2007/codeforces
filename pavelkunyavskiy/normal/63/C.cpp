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

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

typedef long long int64;
typedef long double ld;

bool check(string a,string b,int tor,int cow){
    for (int i=0;i<4;i++){
        if (a[i] == b[i]){
            --tor;
            continue;
        }
        for (int j=0;j<4;j++)
            if (a[i]==b[j]){
                --cow;
                break;
            }               
    }
    return (tor ==0 && cow == 0);
}


string a[15];
int c[15];
int t[15];
int n;

string tostring(int a){
    string s="";
    for (int i=0;i<4;i++){  
        char c=char(a%10+'0');
        s=c+s;
        for (int j=1;j<=i;j++)
            if (s[j]==c)
                return "";
        a/=10;
    }
    return s;
}

bool check(int v){
    string tmp=tostring(v);
    if (tmp.size()!=4)
        return 0;
    for (int i=0;i<n;i++)
        if (!check(a[i],tmp,t[i],c[i]))
            return 0;
    return 1;
}



int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i]>>t[i]>>c[i];
    int cnt=0,val=-1;
    for (int i=0;i<=9999;i++)
        if (check(i)){
            ++cnt;
            val=i;
//          cerr<<i<<endl;
        }
        
    if (cnt==0)
        cout<<"Incorrect data"<<endl;
    else if (cnt==1)
        cout<<tostring(val)<<endl;
    else 
        cout<<"Need more data"<<endl;
    return 0;
}