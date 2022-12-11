#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 100005

bool match(string a,string b){
    if(a.size()!=b.size())return false;
    for(int j = 0;j<b.size();j++){
        if(a[j]=='.') continue;
        if(a[j]!=b[j]) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string words[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    string a;
    cin >> a >> a;
    for(int j = 0;j<8;j++){
        if(match(a,words[j]) == true){
            cout << words[j];
            exit(0);
        }
    }
    return 0;
}