{-# LANGUAGE ScopedTypeVariables #-}
import Control.Monad
import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as B

step :: (Int -> Int -> Int) -> Int -> [Int] -> [Int] -> [Int]
step op e dp xs = tail $ scanl' (\v (w,x) -> x + op v w) e (zip dp xs)

inf = 10^9 :: Int

solve :: [[Int]] -> Bool
solve arr = even vmin && vmin <= 0 && vmax >= 0
  where
    m = length arr
    n = length $ arr !! 0
    vmin = last $ foldl' (step min inf) (0 : repeat inf) arr
    vmax = last $ foldl' (step max (-inf)) (0 : repeat (-inf)) arr

readInts :: IO [Int]
readInts = map (fst  . fromJust . B.readInt) . B.words <$> B.getLine

main :: IO ()
main = do
  [tc] <- readInts
  replicateM_ tc $ do
    [m,n] <- readInts
    arr <- replicateM m readInts
    putStrLn $ if solve arr then "YES" else "NO"