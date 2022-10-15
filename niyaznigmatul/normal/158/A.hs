import Data.List

solve :: Int -> Int -> [Int] -> Int
solve n k a = length [x | x <- a, x > 0, x >= z]
              where z = a !! (k - 1)

main = do {
    z1 <- getLine;
    z2 <- getLine;
    let
        [n, k] = map read (words z1)
    in
        putStrLn $ show $ solve n k (map read (words z2))
}