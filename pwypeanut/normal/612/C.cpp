#include <bits/stdc++.h>
using namespace std;

string S1;
stack<char> S;

void test() {
    if (S.size() == 0) {
        printf("Impossible\n");
        exit(0);
    }
}

int main() {
    int ans = 0;
    cin >> S1;
    for (int i = 0; i < S1.length(); i++) {
        if (S1[i] == '(' || S1[i] == '{' || S1[i] == '<' || S1[i] == '[') S.push(S1[i]);
        else {
            if (S1[i] == ')') {
                test();
                if (S.top() != '(') ans++;
                S.pop();
            } else if (S1[i] == '}') {
                test();
                if (S.top() != '{') ans++;
                S.pop();
            } else if (S1[i] == '>') {
                test();
                if (S.top() != '<') ans++;
                S.pop();
            } else {
                test();
                if (S.top() != '[') ans++;
                S.pop();
            }
        }
    }
    if (S.size() > 0) printf("Impossible\n");
    else printf("%d\n",ans);
}