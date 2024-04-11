#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define MINX(a,b) if (a>b) a=b;
#define MAXX(a,b) if (a<b) a=b;
#define endl '\n'
typedef long long ll;
using namespace std;
string t;
string solve(int a,int b){
    int l=a;
    int r=b;
    string res="";
    int n=(int)t.size();
    while (l<r){
        if (t[l]==t[r]){
            res+=t[l];
            l++;
            r--;
        } else if (t[r-1]==t[l] && r-1>l){
            res+=t[l];
            r-=2;
            l++;
        } else if (t[l+1]==t[r] && r>l+1){
            res+=t[r];
            r--;
            l+=2;
        } else if (l+1<r-1){
            res+=t[l+1];
            l+=2;
            r-=2;
        } else {
            string res1=res;
            reverse(res1.begin(),res1.end());
            return res+t[l]+res1;
        }
    }
   if (l==r){
            string res1=res;
            reverse(res1.begin(),res1.end());
            return res+t[l]+res1;
   } else {
            string res1=res;
            reverse(res1.begin(),res1.end());
            return res+res1;
   }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    int n=(int)t.size();
    t="#"+t;
    cout<<solve(1,n)<<endl;
    return 0;
}
/*
6 3
18 75 245 847 1859 26
*/