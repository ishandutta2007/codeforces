#include <bits/stdc++.h>
using namespace std;

string S, tmp;
vector<string> V, numbers, non;

int main() {
    cin >> S;
    string tmp = "";
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ';' || S[i] == ',') {
            V.push_back(tmp);
            tmp = "";
        } else tmp += S[i];
    }
    V.push_back(tmp);
    for (int i = 0; i < V.size(); i++) {
        if (V[i].length() == 0) non.push_back(V[i]);
        else if (V[i][0] == '0' && V[i].length() != 1) non.push_back(V[i]);
        else {
            bool let = 0;
            for (int j = 0; j < V[i].length(); j++) if (!(V[i][j] >= '0' && V[i][j] <= '9')) let = 1;
            if (let) non.push_back(V[i]);
            else numbers.push_back(V[i]);
        }
    }
    if (numbers.size() == 0) printf("-");
    else {
        printf("\"");
        for (int i = 0; i < numbers.size(); i++) {
            if (i) printf(",");
            printf("%s", numbers[i].c_str());
        }
        printf("\"");
    }
    printf("\n");

    if (non.size() == 0) printf("-");
    else {
        printf("\"");
        for (int i = 0; i < non.size(); i++) {
            if (i) printf(",");
            printf("%s", non[i].c_str());
        }
        printf("\"");
    }
    printf("\n");
}