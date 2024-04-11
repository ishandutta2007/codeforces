#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()

const int INF = 1e9 + 1;
const ll LINF = 1e18 + 1;

int n;

int X1_1 = 1;
int Y1_1 = 1;
int X2_1 = 2;
int Y2_1 = 2;

int X1_2 = 4;
int Y1_2 = 4;
int X2_2 = 5;
int Y2_2 = 5;

int ask(int x1, int y1, int x2, int y2) {
    #ifdef TEST
    int ans = 0;
    if (x1 <= X1_1 && X2_1 <= x2 && y1 <= Y1_1 && Y2_1 <= y2) {
        ans++;
    }
    if (x1 <= X1_2 && X2_2 <= x2 && y1 <= Y1_2 && Y2_2 <= y2) {
        ans++;
    }
    return ans;
    #else
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int res;
    cin >> res;
    return res;
    #endif
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin >> n;
    
    int lx, rx, ly, ry;
    
    {
        int left = 0;
        int right = n;
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            if (ask(1, 1, mid, n) == 2) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        rx = right;
    }
    
    {
        int left = 1;
        int right = n + 1;
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            if (ask(mid, 1, n, n) == 2) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        lx = left;
    }
    
    {
        int left = 0;
        int right = n;
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            if (ask(1, 1, n, mid) == 2) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        ry = right;
    }
    
    {
        int left = 1;
        int right = n + 1;
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            if (ask(1, mid, n, n) == 2) {
                left = mid;
            } else {
                right = mid;
            }
        }
        
        ly = left;
    }
    
    int bord_x;
    
    {
        int left = lx - 1;
        int right = rx;
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            if (ask(lx, ly, mid, ry) == 1) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        bord_x = right;
    }
    
    int bord_y;
    
    {
        int left = ly - 1;
        int right = ry;
        
        while (right - left > 1) {
            int mid = (left + right) / 2;
            
            if (ask(lx, ly, rx, mid) == 1) {
                right = mid;
            } else {
                left = mid;
            }
        }
        
        bord_y = right;
    }
        
    if (bord_x == rx || ask(bord_x + 1, ly, rx, ry) != 1) {
        if (bord_y == ry || ask(lx, bord_y + 1, rx, ry) != 1) {
            assert(false);
        }
        
        int y1_1 = ly;
        int y2_1 = bord_y;
        
        int x1_1, x2_1;
        
        {
            int left = lx - 1;
            int right = rx;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(lx, y1_1, mid, y2_1) == 1) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            
            x2_1 = right;
        }
        
        {
            int left = lx;
            int right = rx + 1;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(mid, y1_1, rx, y2_1) == 1) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            
            x1_1 = left;
        }
        
        int y1_2;
        int y2_2 = ry;
        int x1_2, x2_2;
        
        {
            int left = bord_y + 1;
            int right = ry + 1;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(lx, mid, rx, ry) == 1) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            
            y1_2 = left;
        }
        
        {
            int left = lx - 1;
            int right = rx;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(lx, y1_2, mid, y2_2) == 1) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            
            x2_2 = right;
        }
        
        {
            int left = lx;
            int right = rx + 1;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(mid, y1_2, rx, y2_2) == 1) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            
            x1_2 = left;
        }
        
        cout << "! " << x1_1 << " " << y1_1 << " " << x2_1 << " " << y2_1 << " " << x1_2 << " " << y1_2 << " " << x2_2 << " " << y2_2 << endl;
    } else {
        int x1_1 = lx;
        int x2_1 = bord_x;
        
        int y1_1, y2_1;
        
        {
            int left = ly - 1;
            int right = ry;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(x1_1, ly, x2_1, mid) == 1) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            
            y2_1 = right;
        }
        
        {
            int left = ly;
            int right = ry + 1;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(x1_1, mid, x2_1, ry) == 1) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            
            y1_1 = left;
        }
        
        int x1_2;
        int x2_2 = rx;
        int y1_2, y2_2;
        
        {
            int left = bord_x + 1;
            int right = rx + 1;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(mid, ly, rx, ry) == 1) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            
            x1_2 = left;
        }
        
        {
            int left = ly - 1;
            int right = ry;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(x1_2, ly, x2_2, mid) == 1) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            
            y2_2 = right;
        }
        
        {
            int left = ly;
            int right = ry + 1;
            
            while (right - left > 1) {
                int mid = (left + right) / 2;
                
                if (ask(x1_2, mid, x2_2, ry) == 1) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            
            y1_2 = left;
        }
        
        cout << "! " << x1_1 << " " << y1_1 << " " << x2_1 << " " << y2_1 << " " << x1_2 << " " << y1_2 << " " << x2_2 << " " << y2_2 << endl;
    }
    
	return 0;
}