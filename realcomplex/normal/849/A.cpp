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

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin >> n;
    if(n%2==0){
        cout << "No";
        exit(0);
    }
    int s[n];
    for(int j = 0;j<n;j++){
        cin >> s[j];
    }
    if(s[0]%2 == 1 && s[n-1]%2==1){
        cout << "Yes";
        exit(0);
    }
    cout << "No";
    return 0;
}