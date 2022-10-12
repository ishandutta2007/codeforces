#include<bits/stdc++.h>
using namespace std;

int n, m, w[505];
bool baca[505]={};
int ke;
vector <int> buku;

int main(){
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++){
        scanf("%d", &w[i]);
    }
    int tot = 0;
    int ans = 0;
    for (int i=0; i<m; i++){
        scanf("%d", &ke); ke--;
        if (!baca[ke]){
            ans += tot;
            tot += w[ke];
            buku.push_back(ke);
        }
        else {
            for (int i=0; i<buku.size(); i++){
                if (buku[i] == ke){
                    for (int j=i; j<buku.size()-1; j++){
                        buku[j] = buku[j+1];
                        ans += w[buku[j]];
                    }
                    buku[buku.size()-1] = ke;
                    break;
                }
            }
        }
        baca[ke] = true;
    }
    cout << ans << endl;
    return 0;
}