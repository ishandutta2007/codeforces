#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //open();
    int n;
    cin >> n;
    while(n%10==0)n/=10;
    string s;
    while(n>0){
        s += char((n%10)+48);
        n/=10;
    }
    if(s == string(s.rbegin(),s.rend())) cout << "YES";
    else cout << "NO";
    return 0;
}