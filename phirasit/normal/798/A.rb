inp = gets.to_s.strip

def palindrome(s)
    return s == s.reverse
end

inp.chars.map.with_index { |c, i|
    for ch in ('a'...'z')
        nws = inp.chars.map.with_index { |x, idx| idx == i ? ch : x }.join
        if ch != c and palindrome(nws)
            puts "YES"
            exit
        end
    end
}
puts "NO"