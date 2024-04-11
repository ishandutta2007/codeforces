import Data.Char

solve :: [Int] -> String -> Int
solve a [] = 0
solve a (b:c) = (a !! (ord(b) - ord('1'))) + (solve a c)


main = do
         line <- getLine
         s <- getLine
         print $ solve (map read $ words line) s