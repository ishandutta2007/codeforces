#include "bits/stdc++.h"
using namespace std;
string str1;
string str2;
int n;
int t1;
char player;
int num;
char card;
map < int , int > m1;
map < int , int > m2;
int main(){
    cin >> str1;
    cin >> str2;
    cin >> n;
    while(n--){
        cin >> t1;
        cin >> player;
        cin >> num;
        cin >> card;
        if(player == 'a'){
            m1[num] += (card == 'y') ? 1 : 2;
            if(m1[num] >= 2){
                cout << str2 << " " << num << " " << t1 << endl;
                m1[num] = -99999999;
            }
        }
        else{
            m2[num] += (card == 'y') ? 1 : 2;
            if(m2[num] >= 2){
                cout << str1 << " " << num << " " << t1 << endl;
                m2[num] = -99999999;
            }
        }
    }
}