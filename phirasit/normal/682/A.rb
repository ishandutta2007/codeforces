n, m = gets.strip.split.map(&:to_i)
mod = 5
puts (0...mod).map { |x| 
		( ( n - x ) / mod + 1 - ( x == 0 ? 1 : 0 ) ) * 
		( ( m - (mod-x) % mod ) / mod + 1 - ( x == 0 ? 1 : 0 ) ) 
	}.reduce(0, :+)