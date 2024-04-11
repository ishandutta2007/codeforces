                            /* in the name of Allah */
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#define P pair<int, int>

int n, m;
P arr[50];
int out[1010];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    int rem = n;
    sort(arr, arr + m);
    reverse(arr, arr + m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j+=2){
            if(out[j] != 0) continue;
            int bef = (j + n - 1) % n;
            int nex = (j + 1) % n;
            if(arr[i].first > 0 && out[bef] != arr[i].second && out[nex] != arr[i].second){
                arr[i].first--;
                out[j] = arr[i].second;
                rem--;
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(out[j] != 0) continue;
            int bef = (j + n - 1) % n;
            int nex = (j + 1) % n;
            if(arr[i].first > 0 && out[bef] != arr[i].second && out[nex] != arr[i].second){
                arr[i].first--;
                out[j] = arr[i].second;
                rem--;
            }
        }
    }
    if(rem > 0)
        cout << -1 << endl;
    else{
        for(int i = 0; i < n; i++){
            if(i > 0) cout << ' ';
            cout << out[i];
        }
        cout << endl;
    }
    //cin >> n;
    return 0;
}