#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int n;

vector<int> p[101010];
int c[101010];
double z[101010];

void haku1(int s) {
    c[s] = 1;
    for (int i = 0; i < p[s].size(); i++) {
        haku1(p[s][i]);
        c[s] += c[p[s][i]];
    }
}

void haku2(int s, double e) {
    e++;
    z[s] = e;
    for (int i = 0; i < p[s].size(); i++) {
        haku2(p[s][i],e+(double)(c[s]-c[p[s][i]]-1)/2);
    }
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        p[x].push_back(i);
    }
    haku1(1);
    haku2(1,0);
    for (int i = 1; i <= n; i++) {
        printf("%.9lf ", z[i]);
    }
    printf("\n");
}