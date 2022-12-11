n = gets.strip.to_i
puts -1 if n == 1
puts [n, n+1, n*n+n].map(&:to_s).join(' ') if n != 1