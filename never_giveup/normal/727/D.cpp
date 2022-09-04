#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

int e[6], n;

int answer[maxn];

int need[maxn];

bool is[maxn];

int parse(string s){
    if (s == "S")
        return 0;
    if (s == "M")
        return 1;
    if (s == "L")
        return 2;
    if (s == "XL")
        return 3;
    if (s == "XXL")
        return 4;
    if (s == "XXXL")
        return 5;
}

string obr(int s){
    if (s == 0)
        return "S";
    if (s == 1)
        return "M";
    if (s == 2)
        return "L";
    if (s == 3)
        return "XL";
    if (s == 4)
        return "XXL";
    if (s == 5)
        return "XXXL";
}

vector<int> p[5];

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    for (int i = 0; i < 6; i++)
        cin >> e[i];
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        int have = s.length();
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ',')
                have = i;
        string now;
        for (int i = 0; i < have; i++)
            now.push_back(s[i]);
        need[i] = parse(now);
        if (have == s.length())
            is[i] = 1, answer[i] = need[i], e[need[i]]--;
        else
            p[need[i]].push_back(i);
    }
    for (int i = 0; i < 6; i++)
    if (e[i] < 0){
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < 5; i++){
        int pos = 0;
        while (pos < (int)p[i].size() && e[i] > 0)
            answer[p[i][pos]] = i, e[i]--, pos++;
        if (e[i] == 0){
            while (pos < (int)p[i].size() && e[i + 1] > 0)
                answer[p[i][pos]] = i + 1, e[i + 1]--, pos++;
            if (pos < (int)p[i].size()){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << obr(answer[i]) << '\n';
}