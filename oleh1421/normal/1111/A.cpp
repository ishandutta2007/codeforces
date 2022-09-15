#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int a[200];
int main()
{
    string s,t;cin>>s>>t;
    if (s.size()!=t.size()){
        cout<<"NO";
        return 0;
    }
    a[int('a')]=1;
    a[int('e')]=1;
    a[int('o')]=1;
    a[int('u')]=1;
    a[int('i')]=1;
    for (int i=0;i<s.size();i++){
        if (a[int(s[i])]!=a[int(t[i])]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}