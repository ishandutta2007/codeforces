#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> v1;
int t[27];
string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.length(); i++) t[s[i] - 'a']++;
    for (int i = 0; i < 26; i++) if (t[i] % 2 == 1) v.push_back(i);
    if (s.length() % 2 == 0) {
        for (int i = 0; i < v.size()/2; i++) t[v[i]]++;
        for (int i = v.size()/2; i < v.size(); i++) t[v[i]]--;
        for (int i = 0; i < 26; i++) for (int j = 0; j < t[i]; j++) v1.push_back(i);
        for (int i = 0; i < v1.size(); i+=2) printf("%c", 'a' + v1[i]);
        for (int i = v1.size() - 2; i >= 0; i-=2) printf("%c", 'a' + v1[i]);
        printf("\n");
    } else {
        for (int i = 0; i < v.size()/2; i++) t[v[i]]++;
        for (int i = v.size()/2; i < v.size(); i++) t[v[i]]--;
        int mid = v[v.size()/2];
        for (int i = 0; i < 26; i++) for (int j = 0; j < t[i]; j++) v1.push_back(i);
        for (int i = 0; i < v1.size(); i+=2) printf("%c", 'a' + v1[i]);
        printf("%c", 'a' +mid);
        for (int i = v1.size() - 2; i >= 0; i-=2) printf("%c", 'a' + v1[i]);
        printf("\n");
    }
}