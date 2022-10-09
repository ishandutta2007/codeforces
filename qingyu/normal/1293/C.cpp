/**************************************************************
    Problem: 1018
    User: qingyu
    Language: C++
    Result: Accepted
    Time:576 ms
    Memory:11060 kb
****************************************************************/
 
#include <bits/stdc++.h>
 
const int N = 8e5 + 5;
 
int n, m;
 
inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }
 
struct Node
{
    int left, right;
    bool u, d, l, r, p, q;
    // u: LeftUp to RightUp         d: LeftDown to RightDown
    // l: LeftUp to LeftDown        r: RightUp to RightDown
    // p: LeftUp to RightDown       q: LeftDown to RightUp
} seg[N];
 
bool connect[N][2];
 
inline void push_up(Node &x, Node &LeftChild, Node &RightChild)
{
    x.left = LeftChild.left; x.right = RightChild.right;
    x.l = (LeftChild.l) or (LeftChild.u & connect[LeftChild.right][0] & RightChild.l & connect[LeftChild.right][1] & LeftChild.d);
    x.r = (RightChild.r) or (RightChild.u & connect[LeftChild.right][0] & LeftChild.r & connect[LeftChild.right][1] & RightChild.d);
    x.u = (LeftChild.u & connect[LeftChild.right][0] & RightChild.u) or (LeftChild.p & connect[LeftChild.right][1] & RightChild.q);
    x.d = (LeftChild.d & connect[LeftChild.right][1] & RightChild.d) or (LeftChild.q & connect[LeftChild.right][0] & RightChild.p);
    x.p = (LeftChild.u & connect[LeftChild.right][0] & RightChild.p) or (LeftChild.p & connect[LeftChild.right][1] & RightChild.d);
    x.q = (LeftChild.d & connect[LeftChild.right][1] & RightChild.q) or (LeftChild.q & connect[LeftChild.right][0] & RightChild.u);
}
 
 
inline void DEBUG(Node &x)
{
    printf("l = %d, r = %d, u = %d, d = %d, p = %d, q = %d\n", x.l, x.r, x.u, x.d, x.p, x.q);
}
void Build(int o, int l, int r)
{
    if (l == r)
    {
        seg[o].left = seg[o].right = l;
        seg[o].u = seg[o].d = true;
    }
    else
    {
        const int mid = l + r >> 1;
        Build(lc(o), l, mid);
        Build(rc(o), mid + 1, r);
        push_up(seg[o], seg[lc(o)], seg[rc(o)]);
    }
}
 
void ModCol(int o, int l, int r, int p, bool s)
{
    //if (s) printf("OpenCol %d %d %d %d\n", o, l, r, p);
    //else printf("CloseCol %d %d %d %d\n", o, l, r, p);    
    if (l == r)
    {
        seg[o].l = seg[o].r = seg[o].p = seg[o].q = s;
    }
    else
    {
        const int mid = l + r >> 1;
        if (p <= mid) ModCol(lc(o), l, mid, p, s);
        else ModCol(rc(o), mid + 1, r, p, s);
        push_up(seg[o], seg[lc(o)], seg[rc(o)]);
    }
}
 
void ModRow(int o, int l, int r, int p, int row, bool s)
{
    //if (s) printf("OpenRow %d %d %d %d %d\n", o, l, r, p, row);
    //else printf("CloseRow %d %d %d %d %d\n", o, l, r, p, row);
    const int mid = l + r >> 1;
    if (p == mid) connect[p][row] = s;
    else if (p < mid) ModRow(lc(o), l, mid, p, row, s);
    else ModRow(rc(o), mid + 1, r, p ,row, s);
    push_up(seg[o], seg[lc(o)], seg[rc(o)]);
}
 
Node Query(int o, int l, int r, int ql, int qr)
{
    //printf("Query %d %d %d %d %d\n", o, l, r, ql, qr);
    if (l >= ql && r <= qr) return seg[o];
    const int mid = l + r >> 1;
    if (qr <= mid) return Query(lc(o), l, mid, ql, qr);
    if (ql > mid) return Query(rc(o), mid + 1, r, ql, qr);
    Node result, le = Query(lc(o), l, mid, ql, qr), re = Query(rc(o), mid + 1, r, ql, qr);
    push_up(result, le, re);
    return result;
}
 
inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}
 
inline int read()
{
    int res = 0;
    char ch;
    do ch = nc(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
    return res;
}
 
inline int readOp()
{
    char ch;
    do ch = nc(); while (ch != 'A' && ch != 'O' && ch != 'E' && ch != 'C');
    if (ch == 'O') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'A') return 3;
    exit(0);
}
 
inline void print(bool t)
{
    puts(t ? "Yes" : "No");
}
 
inline void Open(int r1, int c1, int r2, int c2)
{
	//printf("Open %d %d %d %d\n", r1, c1, r2, c2);
                if (r1 == r2) ModRow(1, 1, n, std::min(c1, c2), r1 - 1, true);
                else ModCol(1, 1, n, c1, true);
}
 
inline void Close(int r1, int c1, int r2, int c2)
{
	
	//printf("Close %d %d %d %d\n", r1, c1, r2, c2);
                if (r1 == r2) ModRow(1, 1, n, std::min(c1, c2), r1 - 1, false);
                else ModCol(1, 1, n, c1, false);
}
 
inline void Query(int r1, int c1, int r2, int c2)
{
 
                if (c1 > c2) std::swap(c1, c2), std::swap(r1, r2);
                Node LA = Query(1, 1, n, 1, c1), MA = Query(1, 1, n, c1, c2), RA = Query(1, 1, n, c2, n);
                //DEBUG(LA); DEBUG(MA); DEBUG(RA);
                if (r1 == 1 && r2 == 1)
                {
                    print((MA.u) || (LA.r && MA.d && RA.l));
                }
                else if (r1 == 1 && r2 == 2)
                {
                    print((MA.p) || (LA.r && MA.d) || (MA.u && RA.l));
                }
                else if (r1 == 2 && r2 == 1)
                {
                    print((MA.q) || (LA.r && MA.u) || (MA.d && RA.l));
                }
                else
                {
                    print((MA.d) || (LA.r && MA.u && RA.l));
                }
}
 
bool close[4][N];
 
int main()
{
    n = read(), m = read();
    Build(1, 1, n);
	for (int i = 1; i <= n; ++i)
	{
		Open(2, i, 1, i);
		if (i > 1) Open(1, i, 1, i - 1), Open(2, i, 2, i - 1);
	}
	for (int i = 1; i <= m; ++i)
	{
		int x = read(), y = read();
		if (close[x][y] == false)
		{
			close[x][y] = true;
			if (y > 1) Close(x, y, x, y - 1);
			if (y < n) Close(x, y, x, y + 1);
			Close(2, y, 1, y);
		}
		else
		{
			close[x][y] = false;
			if (y > 1 && close[x][y - 1] == false) Open(x, y, x, y - 1);
			if (y < n && close[x][y + 1] == false) Open(x, y, x, y + 1);
			if (close[1][y] == false && close[2][y] == false) Open(1, y, 2, y);
		}
		Query(1, 1, 2, n);
	}
    return 0;
}