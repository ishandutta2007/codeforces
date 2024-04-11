#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, a, b, x, y;
    cin >> n >> a >> b;

    x=a;
    y=b;
    string s;
    cin >> s;

    string t = "K";
    t.append(s);

    for(int i=1; i<n+1; i++){
        if(t[i] == '.'){
            if(t[i-1] !='a' && t[i-1]!='b'){
                if(a>=b){
                    t[i]='a';
                    a--;
                }

                else {
                    t[i]='b';
                    b--;
                }
            }

            if(t[i-1] == 'a'){
                if(b>0){
                    t[i]='b';
                    b--;
                }
            }

            if(t[i-1] == 'b'){
                if(a>0){
                    t[i]='a';
                    a--;
                }
            }
        }

        if(a==0 && b==0) break;
    }

    cout << (x-a) + (y-b);

}