import Data.List
import Data.Array

readColors :: Int -> IO [Int]
readColors 0 = return []
readColors n = do 
    s <- getLine
    tail <- readColors $ n - 1
    return ((case s of
                "purple" -> 0
                "green" -> 1
                "blue" -> 2
                "orange" -> 3
                "red" -> 4
                "yellow" -> 5) : tail)

printAns :: [Int] -> IO ()
printAns [] = return ()
printAns (a : tail) = do
    putStrLn $ case a of
        0 -> "Power"
        1 -> "Time"
        2 -> "Space"
        3 -> "Soul"
        4 -> "Reality"
        5 -> "Mind"
    printAns tail
    return ()

main = do
    s <- getLine
    let n = read s :: Int
    arr <- readColors n
    let ans = filter (\x -> not $ elem x arr) [0..5]
    print $ length ans
    printAns ans