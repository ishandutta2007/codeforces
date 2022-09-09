#include <cstdio>
#include <iostream>
#include <assert.h>

using namespace std;
const long long BBN = 1000000007;

int n, mas[3][10000], xo, yo;
string s;

long long numd() {
    long long masd[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, nmas[12];
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 12; ++k) {
            nmas[k] = 0;
        }
        //nmas = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        if (mas[0][i] == 0 && mas[1][i] == 0 && mas[2][i] == 0) {
            nmas[0] = masd[11] + masd[3] + masd[6];      
            nmas[1] = masd[11] + masd[3] + masd[6];
            nmas[2] = masd[11] + masd[3] + masd[6];
            nmas[3] = masd[1] + masd[10];
            nmas[4] = masd[1] + masd[10];
            nmas[5] = masd[9];
            nmas[6] = masd[0] + masd[8];
            nmas[7] = masd[0] + masd[8];
            nmas[8] = masd[7];
            nmas[9] = masd[5];
            nmas[10] = masd[4];
            nmas[11] = masd[2];
        } else if (mas[0][i] == 1 && mas[1][i] == 0 && mas[2][i] == 0) {
            nmas[0] = 0;      
            nmas[1] = 0;
            nmas[2] = 0;
            nmas[3] = masd[11] + masd[3] + masd[6];
            nmas[4] = masd[11] + masd[3] + masd[6];
            nmas[5] = 0;
            nmas[6] = 0;
            nmas[7] = 0;
            nmas[8] = masd[9];
            nmas[9] = masd[0] + masd[8];
            nmas[10] = 0;
            nmas[11] = masd[4];
        } else if (mas[0][i] == 0 && mas[1][i] == 1 && mas[2][i] == 0) {
            nmas[0] = 0;      
            nmas[1] = 0;
            nmas[2] = 0;
            nmas[3] = 0;
            nmas[4] = 0;
            nmas[5] = masd[11] + masd[3] + masd[6];
            nmas[6] = 0;
            nmas[7] = 0;
            nmas[8] = masd[10] + masd[1];
            nmas[9] = 0;
            nmas[10] = masd[0] + masd[8];
            nmas[11] = masd[5];   
        } else if (mas[0][i] == 0 && mas[1][i] == 0 && mas[2][i] == 1) {
            nmas[0] = 0;      
            nmas[1] = 0;
            nmas[2] = 0;
            nmas[3] = 0;
            nmas[4] = 0;
            nmas[5] = 0;
            nmas[6] = masd[11] + masd[3] + masd[6];
            nmas[7] = masd[11] + masd[3] + masd[6];
            nmas[8] = 0;
            nmas[9] = masd[1] + masd[10];
            nmas[10] = masd[9];
            nmas[11] = masd[7];   
        } else if (mas[0][i] == 1 && mas[1][i] == 1 && mas[2][i] == 0) {
            nmas[0] = 0;      
            nmas[1] = 0;
            nmas[2] = 0;
            nmas[3] = 0;
            nmas[4] = 0;
            nmas[5] = 0;
            nmas[6] = 0;
            nmas[7] = 0;
            nmas[8] = masd[11] + masd[3] + masd[6];
            nmas[9] = 0;
            nmas[10] = 0;
            nmas[11] = masd[0] + masd[8];   
        } else if (mas[0][i] == 1 && mas[1][i] == 0 && mas[2][i] == 1) {
            nmas[0] = 0;      
            nmas[1] = 0;
            nmas[2] = 0;
            nmas[3] = 0;
            nmas[4] = 0;
            nmas[5] = 0;
            nmas[6] = 0;
            nmas[7] = 0;
            nmas[8] = 0;
            nmas[9] = masd[11] + masd[3] + masd[6];
            nmas[10] = 0;
            nmas[11] = masd[9];   
        } else if (mas[0][i] == 0 && mas[1][i] == 1 && mas[2][i] == 1) {
            nmas[0] = 0;      
            nmas[1] = 0;
            nmas[2] = 0;
            nmas[3] = 0;
            nmas[4] = 0;
            nmas[5] = 0;
            nmas[6] = 0;
            nmas[7] = 0;
            nmas[8] = 0;
            nmas[9] = 0;
            nmas[10] = masd[11] + masd[3] + masd[6];
            nmas[11] = masd[1] + masd[10];   
        } else if (mas[0][i] == 1 && mas[1][i] == 1 && mas[2][i] == 1) {
            nmas[0] = 0;      
            nmas[1] = 0;
            nmas[2] = 0;
            nmas[3] = 0;
            nmas[4] = 0;
            nmas[5] = 0;
            nmas[6] = 0;
            nmas[7] = 0;
            nmas[8] = 0;
            nmas[9] = 0;
            nmas[10] = 0;
            nmas[11] = masd[11] + masd[3] + masd[6];   
        }
        for (int k = 0; k < 12; ++k) {
            masd[k] = nmas[k] % BBN;
        } 
    }
    //cout << masd[11] << " " << masd[3] << " " << masd[6] << endl;
    return (masd[11] + masd[3] + masd[6]) % BBN;
}

int main() {
    cin >> n;
    for (int i = 0; i < 3; ++i) {
        cin >> s;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'X') {
                mas[i][j] = 1;    
            }
            if (s[j] == 'O') {
                mas[i][j] = 1;
                yo = i;
                xo = j;    
            }
        }
    }
    long long ans = 0;
    //cout << "@";
    if (yo == 0) {
        int maswq[3] = {0, 0, 0};
        if (xo > 1 && mas[yo][xo - 1] == 0 && mas[yo][xo - 2] == 0) {
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            ans += numd();
            mas[yo][xo - 1] = 0;
            mas[yo][xo - 2] = 0;
            maswq[0] = 1;
        } 
        if (mas[1][xo] == 0 && mas[2][xo] == 0) {
            mas[1][xo] = 1;
            mas[2][xo] = 1;
            ans += numd();
            mas[1][xo] = 0;
            mas[2][xo] = 0;
            maswq[1] = 1;
        }
        if (xo < n - 2 && mas[yo][xo + 1] == 0 && mas[yo][xo + 2] == 0) {
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            ans += numd();
            mas[yo][xo + 1] = 0;
            mas[yo][xo + 2] = 0;
            maswq[2] = 1;
        }
        if (maswq[0] == 1 && maswq[1] == 1 && maswq[2] == 1) {
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[1][xo] = 1;
            mas[2][xo] = 1;
            ans -= numd();
            mas[yo][xo - 1] = 0;
            mas[yo][xo - 2] = 0;
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            ans -= numd();
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[1][xo] = 0;
            mas[2][xo] = 0;
            ans -= numd();
            mas[1][xo] = 1;
            mas[2][xo] = 1;
            ans += numd();
        } else if (maswq[0] == 1 && maswq[1] == 1) {
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[1][xo] = 1;
            mas[2][xo] = 1;
            ans -= numd();    
        } else if (maswq[2] == 1 && maswq[0] == 1) {
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            ans -= numd();    
        } else if (maswq[2] == 1 && maswq[1] == 1) {
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            mas[1][xo] = 1;
            mas[2][xo] = 1;
            ans -= numd();    
        }
        ans += BBN;
        cout << ans % BBN;
    } else if (yo == 1) {
        int maswq[2] = {0, 0};
        if (xo > 1 && mas[yo][xo - 1] == 0 && mas[yo][xo - 2] == 0) {
            maswq[0] = 1;
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            
            ans += numd();
            mas[yo][xo - 1] = 0;
            mas[yo][xo - 2] = 0;
        } 
        if (xo < n - 2 && mas[yo][xo + 1] == 0 && mas[yo][xo + 2] == 0) {
            maswq[1] = 1;
            //cout << xo << " " << yo;
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            ans += numd();
            mas[yo][xo + 1] = 0;
            mas[yo][xo + 2] = 0;
        }
        if (maswq[0] == 1 && maswq[1] == 1) {
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            ans -= numd();
        }
        ans += BBN;
        if (ans % BBN < 0) {
            cout << maswq[0] << " " << maswq[1] << endl;
            //ans += numd() * 2;
            cout << numd() << endl;
        }
        //assert(ans % BBN >= 0);
        cout << ans % BBN; 
    } else if (yo == 2) {
        
        int maswq[3] = {0, 0, 0};
        if (xo > 1 && mas[yo][xo - 1] == 0 && mas[yo][xo - 2] == 0) {
            maswq[0] = 1;
            //cout << xo << " " << yo;
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            ans += numd();
            mas[yo][xo - 1] = 0;
            mas[yo][xo - 2] = 0;
            //cout << ans;
        } 
        if (mas[1][xo] == 0 && mas[0][xo] == 0) {
            //cout << "@";
            maswq[1] = 1;
            //cout << xo << " " << yo;
            mas[1][xo] = 1;
            mas[0][xo] = 1;
            ans += numd();
            mas[1][xo] = 0;
            mas[0][xo] = 0;
            //cout << ans;
        }
        if (xo < n - 2 && mas[yo][xo + 1] == 0 && mas[yo][xo + 2] == 0) {
            maswq[2] = 1;
            //cout << xo << " " << yo;
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            ans += numd();
            mas[yo][xo + 1] = 0;
            mas[yo][xo + 2] = 0;
        }
        if (maswq[0] == 1 && maswq[1] == 1 && maswq[2] == 1) {
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[1][xo] = 1;
            mas[0][xo] = 1;
            ans -= numd();
            mas[yo][xo - 1] = 0;
            mas[yo][xo - 2] = 0;
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            ans -= numd();
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[1][xo] = 0;
            mas[0][xo] = 0;
            ans -= numd();
            mas[1][xo] = 1;
            mas[0][xo] = 1;
            ans += numd();
        } else if (maswq[0] == 1 && maswq[1] == 1) {
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[1][xo] = 1;
            mas[0][xo] = 1;
            ans -= numd();    
        } else if (maswq[2] == 1 && maswq[0] == 1) {
            mas[yo][xo - 1] = 1;
            mas[yo][xo - 2] = 1;
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            ans -= numd();    
        } else if (maswq[2] == 1 && maswq[1] == 1) {
            mas[yo][xo + 1] = 1;
            mas[yo][xo + 2] = 1;
            mas[1][xo] = 1;
            mas[0][xo] = 1;
            ans -= numd();    
        }
        
        ans += BBN;
        cout << ans % BBN;
    }

    return 0;
}