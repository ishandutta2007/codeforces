import sys
input()
out = []
for line in sys.stdin:
	p,q,b=map(int,line.split())
	out.append('Infinite' if p*pow(b,64,q)%q else 'Finite')
sys.stdout.write('\n'.join(out))