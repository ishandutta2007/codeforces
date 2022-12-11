#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    int cnt1 = 0,cnt2 = 0,cnt3 = 0;
    cin >> s;
    for(auto x : s){
        if(x>='a'&&x<='z') cnt1++;
        else if(x>='A'&&x<='Z') cnt2++;
        else if(x>='0'&&x<='9') cnt3++;
    }
    if(s.size()<5 || cnt1 == 0 || cnt2 == 0 || cnt3 == 0) cout << "Too weak";
    else cout << "Correct";
    return 0;
}