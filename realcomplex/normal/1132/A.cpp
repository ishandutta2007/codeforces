#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void NO(){
    cout << 0;
    exit(0);
}

int main(){
    fastIO;
    int cnt1, cnt2, cnt3, cnt4;
    cin >> cnt1 >> cnt2 >> cnt3 >> cnt4;
    if(cnt1 != cnt4)
        NO();
    if(cnt3 > 0){
        if(cnt1 == 0)
            NO();
    }
    cout << 1;
    return 0;
}