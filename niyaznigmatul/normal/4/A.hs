import Data.List

solve :: Int -> String
solve n
    | n > 2, mod n 2 == 0 = "YES"
    | otherwise           = "NO"

main = do {
    z1 <- getLine;
    putStrLn $ solve $ read z1
}