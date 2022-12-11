#include <bits/stdc++.h>

using namespace std;

int main(){
        int n;
        cin >> n;
        if(n>26){
                cout << -1;
                exit(0);
        }
        char st[n];
        cin >> st;
        set<char>dis;
        for(char x : st){
                dis.insert(x);
        }
        cout << n-dis.size();
        return 0;
}