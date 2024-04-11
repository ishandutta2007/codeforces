#include "bits/stdc++.h"
using namespace std;
int n;
string str;
int main(){
    cin >> n;
    cin >> str;
    int cntr = 0;
    int cntd = 0;
    for(char c : str){
        if(c == 'D'){
            ++cntd;
        }
        if(c == 'R'){
            ++cntr;
        }
    }
    while(1){
        if(!cntr){
            printf("D\n");
            return 0;
        }
        if(!cntd){
            printf("R\n");
            return 0;
        }
        queue < int > d;
        queue < int > r;
        while(!d.empty()){
            d.pop();
        }
        while(!r.empty()){
            r.pop();
        }
        int rdel = 0;
        int ddel = 0;
        int idx = 0;
        for(char c : str){
            ++idx;
            if(c == 'D'){
                if(ddel){
                    --ddel;
                }
                else{
                    ++rdel;
                    d.push(idx);
                    --cntr;
                }
            }
            else{
                if(rdel){
                    --rdel;
                }
                else{
                    ++ddel;
                    r.push(idx);
                    --cntd;
                }
            }
            if(!cntd){
                printf("R\n");
                return 0;
            }
            if(!cntr){
                printf("D\n");
                return 0;
            }
        }
        while(rdel-- && !r.empty()){
            r.pop();
        }
        while(ddel-- && !d.empty()){
            d.pop();
        }
        str = "";
        while(1){
            if(d.empty()){
                while(!r.empty()){
                    str += "R";
                    r.pop();
                }
                break;
            }
            if(r.empty()){
                while(!d.empty()){
                    str += "D";
                    d.pop();
                }
                break;
            }
            if(r.front() < d.front()){
                str += "R";
                r.pop();
            }
            else{
                str += "D";
                d.pop();
            }
        }
    }
}