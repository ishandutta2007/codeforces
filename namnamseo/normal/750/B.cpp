#include <bits/stdc++.h>
using namespace std;
void read(int& x){ scanf("%d",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }

string S("South");
string E("East");
string N("North");
string W("West");

void doom(){ puts("NO"); exit(0); }

int main()
{
    int n;
    read(n);
    int pos=0;
    for(;n--;){
        int val;
        string cmd;
        cin >> val >> cmd;
        if(pos == 0){
            if(cmd != S) doom();
        } else if(pos == 20000){
            if(cmd != N) doom();
        }
        if(cmd == E || cmd == W) continue;
        if(cmd == S) pos += val;
        if(cmd == N) pos -= val;
        
        if(pos > 20000) doom();
        if(pos < 0) doom();
    }
    if(pos != 0) doom();
    puts("YES");
    return 0;
}