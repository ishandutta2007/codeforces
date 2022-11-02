// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

const int N = 300011;

struct node {
    vector<int> next;
    vector<int> inds;
    int num = 0;
    bool isleaf;
};

node bor[300011];
int sz = 0;
int ans = 0;
set<string> se;
vector<string> words;
vector<long long> hashh[N];

void cnthash(string &s, int ind) {
    long long h = 0;
    int p = 31;
    long long pow = 1;
    for (int i = 0; i < s.length(); ++i) {
        h += (s[i] - 'a' + 1) * pow;
        hashh[ind].push_back(h);
        pow *= p;
    }
}

bool ispref(int ind1, int ind2) {
    string s1 = words[ind1];
    string s2 = words[ind2];
    if (s1.length() > s2.length())
        return false;
    return s1 == s2.substr(0, s1.length());
}

void addstring(string s, int ind) {
    int n = s.length();
    int v = 0;
    bool bo = false;
    bool flag = se.find(s) != se.end();
    bool bo1 = true;
    for (int i = 0; i < n; ++i) {
        char c = s[i]-'a';
        if (bor[v].next[c]) {
            v = bor[v].next[c];
            if (!bo)
                ans++;
            if (bo1 && bor[v].num == 1  && !bo && !bor[v].isleaf){
                if (!ispref(bor[v].inds.back(), ind)) {
                    bo1 = false;
                }
                else {
                    ans++;
                    bo = true;
                }
            }
            if (!flag){
                bor[v].inds.push_back(ind);
                bor[v].num++;
            }
        }
        else {
            bor[v].next[c] = ++sz;
            v = sz;
            ans++;
            bor[v].num = 1;
            bor[v].inds.push_back(ind);
        }
    }
    bor[v].isleaf = true;
}

void init() {
    for (int i = 0; i < N; ++i)
        bor[i].next.assign(26, 0);

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    char c;
    string s = "";
    int cnt = 0;
    while ((c = cin.get()) != EOF) {
        cnt++;
        if (c == '.' || c == ',' || c == '?' || c == '!' || c == '\'' || c == ' ' || c == '-' || c == '\n'){
            ans++;
            if (s != ""){
                words.push_back(s);
                cnthash(s, words.size()-1);
                addstring(s, words.size()-1);
                se.insert(s);
            }
            s = "";
        }
        else
            s += c;
    }
    words.push_back(s);
    addstring(s, words.size()-1);
    cout << ans;
    return 0;
}