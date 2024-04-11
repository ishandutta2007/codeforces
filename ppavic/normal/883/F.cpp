#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

const int INF=0x3f3f3f3f;
const int N=405;

int n;
string p[N];
map <string, int> m;
string s;

string convert(string str) {
    string sol="";
    int broj_k=0;
    for (int i=0; i<str.size(); ++i) {
        if (str[i]=='u') {
            if (broj_k>0) {
                for (int j=0; j<broj_k; ++j) sol+='k';
            }
            sol=sol+"oo";
            broj_k=0;
            continue;
        }
        if (str[i]=='k') {
            ++broj_k;
        }
        if (str[i]=='h' && broj_k!=0) {
            sol+="h";
            broj_k=0;
            continue;
        }
        if (str[i]!='k') {
            if (broj_k>0) {
                for (int j=0; j<broj_k; ++j) sol+='k';
            }
            broj_k=0;
            sol+=str[i];
            continue;
        }
    }
     if (broj_k>0) {
        for (int j=0; j<broj_k; ++j) sol+='k';
    }
    return sol;
}

void load() {
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        cin >>s;
        p[i]=convert(s);
        //cout <<"converted: "<<convert(s)<<endl;
    }
}

void solve() {
    int sol=0;
    for (int i=0; i<n; ++i) {
        if (m[p[i]]!=0) continue;
        ++sol;
        m[p[i]]=1;
    }
    printf("%d", sol);
}


int main() {
    load();
    solve();
    return 0;
}