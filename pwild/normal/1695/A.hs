{-# LANGUAGE ScopedTypeVariables #-}
import Control.Monad

main :: IO ()
main = do
  tc <- readLn
  replicateM_ tc $ do
    [m,n] <- map read . words <$> getLine
    arr :: [[Int]] <- replicateM m $ map read . words <$> getLine
    let amax = maximum $ concat arr
    let (imax,jmax) = head $ filter (\(i,j) -> arr !! i !! j == amax) [(i,j) | i <- [0..m-1], j <- [0..n-1]]
    let h = m - min imax (m-1-imax)
    let w = n - min jmax (n-1-jmax)
    print $ h*w