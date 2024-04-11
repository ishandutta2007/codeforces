#include "bits/stdc++.h"
using namespace std;
int hy , ay , dy , hm , am , dm , h , a , d;
int main(){
    //Hm / ( Ay - Dm ) < Hy / (Am - Dy )
    cin >> hy >> ay >> dy;
    cin >> hm >> am >> dm;
    cin >> h  >> a  >>  d;
    int ans = 9999999;
    for(int i = 0 ; i <= 1000 ; ++i){
        for(int j = 0 ; j <= 200 ; ++j){
            for(int k = 0 ; k <= 100 ; ++k){
                int newh = hy + i;
                int newa = ay + j;
                int newd = dy + k;
                int cost = h * i + a * j + d * k;
                int dmgy = newa - dm;
                int dmgm = am - newd;
                if(dmgy <= 0){
                    continue;
                }
                if(dmgm <= 0){
                    ans = min(ans , cost);
                    continue;
                }
                int timey = hm / dmgy;
                int timem = newh / dmgm;
                if(hm % dmgy){
                    timey ++;
                }
                if(newh % dmgm){
                    timem ++;
                }
                if(timey < timem){
                    ans = min(ans , cost);
                }
            }
        }
    }
    cout << ans;
}