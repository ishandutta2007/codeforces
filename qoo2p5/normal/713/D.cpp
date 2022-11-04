#include <bits/stdc++.h>

using namespace std;

const int N = 1024;
const int L = 11;

int n, m;
int s[N][N];

int get_sum(int x1, int y1, int x2, int y2) {
    int res = s[x2][y2];
    res -= (x1 == 0 ? 0 : s[x1 - 1][y2]);
    res -= (y1 == 0 ? 0 : s[x2][y1 - 1]);
    res += ((x1 == 0 || y1 == 0) ? 0 : s[x1 - 1][y1 - 1]);
    return res;
}

int log2z[N];
short sp[N][N][L][L];

void build_sparse() {
    for (int i = 2; i < N; i++) {
        log2z[i] = log2z[i / 2] + 1;
    }
    
    for (int lx = 1; lx < L; lx++) {
        for (int x = 0; x + (1 << lx) - 1 < n; x++) {
            for (int y = 0; y < m; y++) {
                sp[x][y][lx][0] = max(sp[x][y][lx - 1][0], sp[x + (1 << (lx - 1))][y][lx - 1][0]);
            }
        }
    }
    
    for (int ly = 1; ly < L; ly++) {
        for (int x = 0; x < n; x++) {
            for (int y = 0; y + (1 << ly) - 1 < m; y++) {
                sp[x][y][0][ly] = max(sp[x][y][0][ly - 1], sp[x][y + (1 << (ly - 1))][0][ly - 1]);
            }
        }
    }
    
    for (int lx = 1; lx < L; lx++) {
        for (int ly = 1; ly < L; ly++) {
            for (int x = 0; x + (1 << lx) - 1 < n; x++) {
                for (int y = 0; y + (1 << ly) - 1 < m; y++) {
                    sp[x][y][lx][ly] = max(
                        max(sp[x][y][lx - 1][ly - 1], sp[x + (1 << (lx - 1))][y][lx - 1][ly - 1]),
                        max(sp[x][y + (1 << (ly - 1))][lx - 1][ly - 1], sp[x + (1 << (lx - 1))][y + (1 << (ly - 1))][lx - 1][ly - 1])
                    );
                }
            }
        }
    }
}

int get_max(int x1, int y1, int x2, int y2) {
    int lx = log2z[x2 - x1 + 1];
    int ly = log2z[y2 - y1 + 1];
    
    return max(
        max(sp[x1][y1][lx][ly], sp[x2 - (1 << lx) + 1][y1][lx][ly]),
        max(sp[x1][y2 - (1 << ly) + 1][lx][ly], sp[x2 - (1 << lx) + 1][y2 - (1 << ly) + 1][lx][ly])
    );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    scanf("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            scanf("%c", &c);
            if (j == m - 1) {
                scanf("\n");
            } else {
                scanf(" ");
            }
            
            s[i][j] += c == '1' ? 1 : 0;
            s[i][j] += (i == 0 ? 0 : s[i - 1][j]);
            s[i][j] += (j == 0 ? 0 : s[i][j - 1]);
            s[i][j] -= ((i == 0 || j == 0) ? 0 : s[i - 1][j - 1]);
            
            short left = 0;
            short right = min(i + 1, j + 1) + 1;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (get_sum(i - mid + 1, j - mid + 1, i, j) == mid * mid) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            
            sp[i][j][0][0] = left;
        }
    }
    
    build_sparse();
    
    int t;
    scanf("%d\t", &t);
    
    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d\n", &x1, &y1, &x2, &y2);
        x1--; y1--; x2--; y2--;
        
        int left = 0;
        int right = min(x2 - x1 + 1, y2 - y1 + 1) + 1;
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            if (get_max(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        cout << left << "\n";
    }
    
	return 0;
}