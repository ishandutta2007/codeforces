#include <bits/stdc++.h>

using namespace std;

const int nmax = 100005;

struct Coord {
    int x,y;
}v[nmax];

bool check[nmax];

bool coliniare(Coord a, Coord b, Coord c) {
    Coord vec1;
    vec1.x = a.x - b.x;
    vec1.y = a.y - b.y;
    Coord vec2;
    vec2.x = a.x - c.x;
    vec2.y = a.y - c.y;
    long long pret = 1LL * vec1.x * vec2.y - 1LL * vec1.y * vec2.x;
    return pret == 0LL;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++)
        cin >> v[i].x >> v[i].y;
    if(n <= 3) {
        cout << "YES";
        return 0;
    }
    for(int i = 1;i <= 3;i ++) {
        for(int j = 1;j <= 3;j ++) {
            if(i != j) {
                memset(check, 0, sizeof check);
                for(int k = 1;k <= n;k ++) {
                    if(coliniare(v[i],v[j],v[k]) == 1){
                        check[i] = 1;
                        check[j] = 1;
                        check[k] = 1;
                    }
                }
                int a1 = -1,a2 = -1;
                for(int k = 1;k <= n;k ++)
                    if(check[k] == 0)
                        a1 = k;
                for(int k = 1;k <= n;k ++)
                    if(check[k] == 0 && k != a1)
                        a2 = k;
                if(a1 == -1 || a2 == -1){
                    cout << "YES";
                    return 0;
                }
                for(int k = 1;k <= n;k ++){
                    if(coliniare(v[a1],v[a2],v[k]) == 1){
                        check[a1] = 1;
                        check[a2] = 1;
                        check[k] = 1;
                    }
                }
                bool flag = 0;
                for(int k = 1;k <= n;k ++)
                    if(check[k] == 0)
                        flag = 1;
                if(flag == 0){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}