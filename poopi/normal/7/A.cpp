                                /* in the name of Allah */
#include <iostream>
using namespace std;

char ch[10][10];

int main(){
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> ch[i][j];
    int mn = 16;
    for(int m = 0; m < (1 << 16); m++){
        bool can = true;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(ch[i][j] == 'B' && (m & (1 << i)) == 0 && (m & (1 << (j + 8))) == 0)
                    can = false;
                if(ch[i][j] == 'W' && ((m & (1 << i)) || (m & (1 << (j + 8)))))
                    can = false;
            }
        }
        if(can){
            int t = 0;
            for(int i = 0; i < 16; i++)
                if(m & (1 << i))
                    t++;
            mn = min(mn, t);
        }
    }
    cout << mn << endl;
    return 0;
}