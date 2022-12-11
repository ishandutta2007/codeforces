#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;
    cin >> n >> q;
    string k;
    cin >> k;
    char s[n+2];
    s[0] = '+';
    s[n+1] = '-';
    for(int j = 1;j<=n;j++){
        s[j] = k[j-1];
    }
    int cnt = 0;
    for(int i = 1;i<=n+1;i++){
        if(s[i] == '.' && s[i-1] == '.') cnt++;
    }
    int p;
    char val;
    for(int i = 0;i<q;i++){
        cin >> p >> val;
        if(val >= 'a' && val <= 'z'){
            if(s[p] == '.'){
                if(s[p-1] == '.')cnt--;
                if(s[p+1] == '.')cnt--;
            }
        }
        else{
            if(s[p] >= 'a' && s[p] <= 'z'){
                if(s[p-1] == '.')cnt++;
                if(s[p+1] == '.')cnt++;
            }
        }
        s[p] = val;
        cout << cnt << "\n";
    }
    return 0;
}