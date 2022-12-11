#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 100005

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c;
    cin >> a >> b >> c;
    if(a == b) cout << "YES";
    else if(c==0){
        if(a == b)cout << "YES";
        else cout << "NO";
    }
    else{
        if((b-a)%c==0&&(b-a)/c>=0)cout << "YES";
        else cout << "NO";
    }
    return 0;
}