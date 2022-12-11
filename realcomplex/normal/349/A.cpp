#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define f first
#define s second

int ty[3];

int main(){

    int n;
    cin >> n;
    int am;
    bool c = true;
    for(int i = 0;i<n;i++){
        cin >> am;
        if(am == 25){
            ty[0]++;
        }
        else if(am == 50){
            if(ty[0] == 0){
                c = false;
                break;
            }
            else{
                ty[0]--;
                ty[1]++;
            }
        }
        else{
            if(ty[1] > 0 && ty[0] > 0){
                ty[0]--;
                ty[1]--;
                ty[3]++;
            }
            else if(ty[0] > 2){
                ty[0]-=3;
            }
            else{
                c = false;
                break;
            }
        }
    }
    if(c == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}