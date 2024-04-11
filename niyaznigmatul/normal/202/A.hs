import Data.Char
import Data.List

count :: String -> Char -> Int
count s c = length $ filter (\x -> x == c) s

 
solve :: String -> String
solve s = solve' s 'z'

solve' :: String -> Char -> String
solve' s c = let z = count s c in if z > 0 then replicate z c else solve' s (toEnum ((fromEnum c) - 1))
main = do s <- getLine
          putStrLn $ solve s