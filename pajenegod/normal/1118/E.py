import sys
import io

n,k = [int(x) for x in input().split()]
if k*(k-1)<n:
    print('NO')
    sys.exit()

out = io.BytesIO()
out.write(b'YES\n')
a = 0
diff = 1
counter = 0
while counter<n:
    if a==k:
        diff += 1
        a = 0
    if diff == k:
        break
    out.write(str(a+1).encode())
    out.write(b' ')
    out.write(str((a+diff)%k + 1).encode())
    out.write(b'\n')
    a += 1
    counter += 1

sys.stdout.buffer.write(out.getvalue())