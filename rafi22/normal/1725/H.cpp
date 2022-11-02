#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    
    vector<int>ones, zeroes;
    for(int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        a %= 3;
        a = (a * a) % 3;
        if(a == 1)
            ones.push_back(i);
        else
            zeroes.push_back(i);
    }
    
    char *c = new char[n + 1];
    c[n] = 0;
    
    if(ones.size() >= n / 2) {
        for(int i = 0; i < n / 2; i++) {
            c[ones.back()] = '1';
            ones.pop_back();
        }
        
        while(!ones.empty()) {
            c[ones.back()] = '0';
            ones.pop_back();
        }
        
        while(!zeroes.empty()) {
            c[zeroes.back()] = '0';
            zeroes.pop_back();
        }
        
        printf("0\n");
    } else {
        for(int i = 0; i < n / 2; i++) {
            c[zeroes.back()] = '1';
            zeroes.pop_back();
        }
        
        while(!zeroes.empty()) {
            c[zeroes.back()] = '0';
            zeroes.pop_back();
        }
        
        while(!ones.empty()) {
            c[ones.back()] = '0';
            ones.pop_back();
        }
        
        printf("2\n");
    }
    
    printf("%s\n", c);
}