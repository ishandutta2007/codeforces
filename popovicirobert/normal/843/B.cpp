#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 5e4;

bool used[MAXN + 1];

inline pair <int, int> ask(int p) {
    cout << "?" << " " << p << endl;
    fflush(stdout);
    pair <int, int> ans;
    cin >> ans.first >> ans.second;
    return ans;
}

inline void print(int p) {
    cout << "!" << " " << p;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, start, x, i, p;
    ios::sync_with_stdio(false);
    srand(time(NULL));
    cin >> n >> start >> x;
    pair <int, int> pr = {-1, -1};
    for(i = 0; i < 999 && i < n; i++) {
        if(i == 0)
            p = start;
        else {
            do {
                p = abs((rand() << 15) + rand()) % n + 1;
            }while(used[p]);
        }
        used[p] = 1;
        pair <int, int> aux = ask(p);
        if(aux.first < x && aux.first > pr.first)
            pr = aux;
    }
    if(pr.first == -1) {
        pr = ask(start);
        print(pr.first);
    }
    else {
        pair <int, int> aux = pr;
        while(aux.first < x && aux.second != -1) {
            aux = ask(aux.second);
        }
        if(aux.first < x)
            print(-1);
        else
            print(aux.first);
    }
    //cin.close();
    //cout.close();
    return 0;
}