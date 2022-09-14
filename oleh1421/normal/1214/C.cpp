#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
///#define int long long
typedef long long ll;
using namespace std;
const long long mod=1000000007ll;
int a[300001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    string s;cin>>s;
    int sum=0;
    for (auto i:s){
        if (i=='(') sum++;
        else sum--;
    }
    if (sum!=0){
        cout<<"NO";
        return 0;
    }
    int fi=-1;
    for (int i=0;i<n;i++){
        if (s[i]==')'){
            fi=i;
            break;
        }
    }
    int sum1=0;
    for (int i=0;i<fi;i++){
        if (s[i]=='(') sum1++;
        else sum1--;
        if (sum1<0){
            cout<<"NO";
            return 0;
        }
    }
    for (int i=fi+1;i<n;i++){
        if (s[i]=='(') sum1++;
        else sum1--;
        if (sum1<0){
            cout<<"NO";
            return 0;
        }
    }
    sum1--;
    if (sum1<0){
            cout<<"NO";
            return 0;
    }
    cout<<"YES";

    return 0;
}