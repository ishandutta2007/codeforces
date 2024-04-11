#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if(a>b) a=b;
#define MAXX(a,b) if(a<b) a=b;
typedef long long ll;
using namespace std;
int a[111];
int b[111];
int c[111][111];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;cin>>s;
    int fi=-1;
    for (int i=0;i<s.size();i++){
        if (s[i]!='a'){
            fi=i;
            break;
        }
    }
    if (fi==-1){
        s[(int)s.size()-1]='z';
    } else {
        for (int i=fi;i<s.size();i++){
            if (s[i]=='a') break;
            s[i]=char(int(s[i])-1);
        }
    }
    cout<<s;
    return 0;
}
//2 6 -2 -6  2