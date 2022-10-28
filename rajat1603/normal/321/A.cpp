#include "bits/stdc++.h"
using namespace std;
int a , b;
string str;
int sx , sy;
int dx , dy;
void yes(){
    printf("Yes\n");
    exit(0);
}
int main(){
    cin >> a >> b;
    if(a == 0 && b == 0){
        yes();
    }
    cin >> str;
    for(char c : str){
        if(c == 'U'){
            ++sy;
        }
        if(c == 'D'){
            --sy;
        }
        if(c == 'L'){
            --sx;
        }
        if(c == 'R'){
            ++sx;
        }
    }
    for(char c : str){
        if(c == 'U'){
            ++dy;
        }
        if(c == 'D'){
            --dy;
        }
        if(c == 'L'){
            --dx;
        }
        if(c == 'R'){
            ++dx;
        }
        int tmpx = a - dx;
        int tmpy = b - dy;
        if(abs(tmpx) > 0 && sx == 0){
            continue;
        }
        if(abs(tmpy) > 0 && sy == 0){
            continue;
        }
        if(sx == 0){
            if(sy == 0){
                yes();
            }
            else{
                if(abs(tmpy) % abs(sy) == 0){
                    if((tmpy / sy) >= 0){
                        yes();
                    }
                }
            }
        }
        else{
            if(sy == 0){
                if(abs(tmpx) % abs(sx) == 0){
                    if((tmpx / sx) >= 0){
                        yes();
                    }
                }
            }
            else{
                if(abs(tmpx) % abs(sx) == 0){
                    if((tmpx / sx) >= 0){
                        if(abs(tmpy) % abs(sy) == 0){
                            if((tmpy / sy) >= 0){
                                if((tmpx / sx) == (tmpy / sy)){
                                    yes();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("No\n");
}