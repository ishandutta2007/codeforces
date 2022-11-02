#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define x first
#define y second

long long D(pair<int, int>a, pair<int, int>b) {
    return (long long)abs(a.x - b.x) + (long long)abs(a.y - b.y);
}

int main() {
    vector<pair<int, int>>p(3);
    for(auto &[x, y] : p)
        scanf("%d%d", &x, &y);
    
    sort(p.begin(), p.end());
    
    vector<pair<pair<int, int>, pair<int, int>>>S;
    long long bestLen = 1ll << 60;
    
    do {
        long long len = 0;
        vector<pair<pair<int, int>, pair<int, int>>>s;
        
        if(p[0].y != p[1].y) {
            s.emplace_back(p[0], make_pair(p[0].x, p[1].y));
            len += abs(p[0].y - p[1].y);
        }
        
        if(p[0].x != p[1].x) {
            s.emplace_back(make_pair(p[0].x, p[1].y), p[1]);
            len += abs(p[0].x - p[1].x);
        }
        
        if(p[1].y != p[2].y) {
            s.emplace_back(p[1], make_pair(p[1].x, p[2].y));
            len += abs(p[1].y - p[2].y);
        }
        
        if(p[1].x != p[2].x) {
            s.emplace_back(make_pair(p[1].x, p[2].y), p[2]);
            len += abs(p[1].x - p[2].x);
        }
        
        if(len < bestLen) {
            S = s;
            bestLen = len;
        }
            
    } while(next_permutation(p.begin(), p.end()));
    
    sort(p.begin(), p.end());
    
    do {
        long long len = 0;
        vector<pair<pair<int, int>, pair<int, int>>>s;
        
        pair<int, int>a = make_pair(p[0].x, p[1].y);
        pair<int, int>b = make_pair(p[1].x, p[0].y);
        
        if(D(p[2], a) < D(p[2], b)) {
            if(a != p[0])
                s.emplace_back(p[0], a);
            if(a != p[1])
                s.emplace_back(a, p[1]);
            if(a.x != p[2].x)
                s.emplace_back(a, make_pair(p[2].x, a.y));
            if(a.y != p[2].y)
                s.emplace_back(make_pair(p[2].x, a.y), p[2]);
            len = D(p[2], a) + D(p[0], p[1]);
        } else {
            if(b != p[0])
                s.emplace_back(p[0], b);
            if(b != p[1])
                s.emplace_back(b, p[1]);
            if(b.x != p[2].x)
                s.emplace_back(b, make_pair(p[2].x, b.y));
            if(b.y != p[2].y)
                s.emplace_back(make_pair(p[2].x, b.y), p[2]);
            len = D(p[2], b) + D(p[0], p[1]);
        }
        
        if(len < bestLen) {
            S = s;
            bestLen = len;
        }
            
    } while(next_permutation(p.begin(), p.end()));  
    
    
    printf("%d\n", (int)S.size());

    for(pair<pair<int, int>, pair<int, int>>p : S) {
        printf("%d %d %d %d\n", p.first.first, p.first.second, p.second.first, p.second.second);
    }
    
    return 0;
}