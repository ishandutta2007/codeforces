#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int cnt[N],n,k,sol;
string s;

int main(){
    cin >> n >> k >> s;
    sol = 1;
    for(int i = 0;i<s.size();i++){
        cnt[s[i] - 'a']++;
    }
    for(int i = 0;i<26;i++)
        if(cnt[i] > k) sol = 0;
    if(sol) cout << "YES" << endl;
    else cout << "NO" << endl;
}