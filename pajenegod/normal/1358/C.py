import sys
 
class Scanner():
    def __init__(self):
        self.tokens = self.get_tokens()
        self.next_token = self.tokens.__next__
 
    def get_tokens(self):
        yield from (x.decode('ascii') for x in sys.stdin.buffer.read().split())
 
def get_ap_sum(a, d, n):
    x = 2 * a + (n - 1) * d
    return (x * n) >> 1
 
 
def get_first_row_sum(n):
    return (n * (n * n + 5)) // 6
 
 
def get_row_sum(r, n):
    a = ((r * (r + 1)) >> 1) - 1
    d = r - 1
    return get_first_row_sum(n) + get_ap_sum(a, d, n)
 
 
def get_first_col_sum(n):
    return (n * (n + 1) * (n + 2)) // 6
 
 
def get_col_sum(c, n):
    a = ((c * (c - 1)) >> 1)
    d = c - 1
    return get_first_col_sum(n) + get_ap_sum(a, d, n)
 
 
def solve(x1, y1, x2, y2):
    v1 = get_row_sum(x1, y2) - get_row_sum(x1, y1 - 1) + get_col_sum(y2, x2) - get_col_sum(y2, x1)
    v2 = get_col_sum(y1, x2) - get_col_sum(y1, x1 - 1) + get_row_sum(x2, y2) - get_row_sum(x2, y1)
    return abs(v1 - v2) + 1
 
 
def main(args):
    sc = Scanner()
 
    out = []
    t = int(sc.next_token())
    for _ in range(t):
        x1 = int(sc.next_token())
        y1 = int(sc.next_token())
        x2 = int(sc.next_token())
        y2 = int(sc.next_token())
        out.append(solve(x1, y1, x2, y2))
 
    print('\n'.join(str(x) for x in out ))
 
 
if __name__ == '__main__':
    sys.exit(main(sys.argv))