
def solve( n, k, data )
	g, t = data.index('G'), data.index('T')
	return "NO" if g % k != t % k
	return ( ([g, t].min+1...[g, t].max).all? { |x| x % k != g % k or data[x] == '.' } ) ? "YES" : "NO"
end

n, k = gets.split.map(&:to_i)
data = gets

print solve( n, k, data ) + "\n"