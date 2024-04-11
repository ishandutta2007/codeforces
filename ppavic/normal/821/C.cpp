#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

const int N = 3e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

set < int > s;
stack < int > st;
int n,x;
int issorted = 1,sol = 0,cnt = 1;
string str;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<2* n;i++){
        cin >> str;
        if(str == "add"){
            cin >> x;
            st.push(x);
            if(s.empty()){
                s.insert(x);
                issorted = 1;
            }
            else if(*s.begin() > x){
                s.insert(x);
            }
            else{
                s.insert(x);
                issorted = 0;
            }
        }
        else{
            if(st.top() != cnt && !issorted){
                sol++;issorted = 1;
            }
            if(st.top() == cnt) st.pop();
            s.erase(cnt);
            cnt++;
        }
    }
    printf("%d\n",sol);
}