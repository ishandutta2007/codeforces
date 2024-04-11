#include "bits/stdc++.h"
using namespace std;
int hh;
int mm;
char tmp;
int a;
int main(){
    cin >> hh >> tmp >> mm >> a;
    while(a--){
        ++mm;
        if(mm == 60){
            mm = 0;
            ++hh;
            if(hh == 24){
                hh = 0;
            }
        }
    }
    printf("%.2d:%.2d" , hh , mm);
}