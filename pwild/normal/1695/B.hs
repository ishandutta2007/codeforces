{-# LANGUAGE ScopedTypeVariables #-}
import Control.Monad
import Data.List

solve :: IO ()
solve = do
  n :: Int <- read <$> getLine
  xs :: [Int] <- map read . words <$> getLine
  let Just i = elemIndex (minimum xs) xs
  putStrLn $ if odd n || odd i then "Mike" else "Joe"

main :: IO ()
main = do
  tc <- readLn
  replicateM_ tc solve