/*
   .
#???????
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair

bool comp(string a,string b){
    return (a+b)<(b+a);
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for(int i = 0;i<n;i++){
        cin >> s[i];
    }
    sort(s,s+n,comp);
    for(int j = 0;j<n;j++){
        cout << s[j];
    }
    return 0;
}